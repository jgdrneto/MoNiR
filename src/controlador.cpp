
Controlador::Controlador(Reservatorio& r){
	
	this->reservatorio = r;
	
	this->dispositivos.push_back(new Led("Verde",PORTNUMBER::P9_16));
	this->dispositivos.push_back(new Led("Vermelho",PORTNUMBER::P9_15));
	this->dispositivos.push_back(new Led("Amarelo",PORTNUMBER::P9_13));
	this->dispositivos.push_back(new Led("Branco",PORTNUMBER::P9_14));
	this->dispositivos.push_back(new SensorUltrasonico("SensorUlt",PORTNUMBER::P9_12,PORTNUMBER::P9_11));
		

}

void Controlador::salvarRelatorio(std::string arquivo,std::vector<Medicao>& medicoes){
	
	nlohmann::json j;

	std::ifstream i(arquivo);
	
	if(!i.is_open()){
		std::fstream s;
		s.open(arquivo,std::fstream::out);
		s.close();
	}

	if(i.peek() != std::ifstream::traits_type::eof()){
    	i >> j;
	}

    i.close();
	
	for(Medicao m : medicoes){

		j.push_back( nlohmann::json{
										{"VOLUME",m.volumeAtual},
										{"DATA",
											nlohmann::json{
												{"HORA",m.data[Data::HORA]},
												{"MIN",m.data[Data::MINUTO]},
												{"SEC",m.data[Data::SEGUNDO]},
												{"DIA",m.data[Data::DIA]},
												{"MES",m.data[Data::MES]},
												{"ANO",m.data[Data::ANO]}
											}
										}
									}
				   );
	}
		
	std::fstream o(arquivo);
    o << std::setw(4) << j << std::endl;
	o.close();
	
}

std::vector<Medicao>& Controlador::realizarMedicoes(unsigned int quantidade, double intervalo){

	std::vector<Medicao>* medicoes =  new std::vector<Medicao>();

	for(unsigned int i=0;i<quantidade;i++){

		//Altura medida no sensor ultrasonico
		double alturaParteVazia = obterDispositivoPorNome("SensorUlt")->acao();

		//Altura do nível atual do reservatório
		double alturaParteCheia = this->reservatorio.forma->dimensoes[0] - alturaParteVazia; 

		//Obtendo o volume atual do reservatório
		double volumeAtual = this->reservatorio.forma->obterVolumeAtual(alturaParteCheia);

		//Obter procentagem do quanto está cheio o resevatório
		unsigned int porcentagemAtual = this->reservatorio.obterPorcentagemCheio(volumeAtual); 

		//Modificar os leds de nível
		modificarLedsNivel(porcentagemAtual);

		//Obter data atual
		Data data = Data::obterDataAtual();

		//Criando a medida
		medicoes->push_back(*(new Medicao(data,volumeAtual)));
		
		std::cout << "Realizado " << (i+1) << "º medição do buffer" << std::endl; 

		usleep(intervalo*1000000);

	}

	//Modifica o led branco de mudança de nível
	bool mandarEmail = modificarLedMudanca(*medicoes,quantidade);

	return *medicoes;

}

void Controlador::modificarLedsNivel(unsigned int porcentagemAtual){

	if(0<=porcentagemAtual && porcentagemAtual<=33){

		((Led*)obterDispositivoPorNome("Vermelho"))->ligar();
		((Led*)obterDispositivoPorNome("Amarelo"))->desligar();
		((Led*)obterDispositivoPorNome("Verde"))->desligar();

	}else if(34<=porcentagemAtual && porcentagemAtual<=66){

		((Led*)obterDispositivoPorNome("Vermelho"))->desligar();
		((Led*)obterDispositivoPorNome("Amarelo"))->ligar();
		((Led*)obterDispositivoPorNome("Verde"))->desligar();

	}else{

		((Led*)obterDispositivoPorNome("Vermelho"))->desligar();
		((Led*)obterDispositivoPorNome("Amarelo"))->desligar();
		((Led*)obterDispositivoPorNome("Verde"))->ligar();

	}

}

bool Controlador::modificarLedMudanca(std::vector<Medicao>& medicoes,unsigned int quantidade){
	
	bool modificou = false;

	std::sort(medicoes.begin(), medicoes.end(),Medicao::comparador);

	double proporcao = medicoes[0].volumeAtual/medicoes[medicoes.size()-1].volumeAtual;

	if(proporcao<=0.9){
		((Led*)obterDispositivoPorNome("Branco"))->ligar();
		modificou = true;
	}else{
		((Led*)obterDispositivoPorNome("Branco"))->desligar();
		modificou = false;
	}

	return modificou;
}

Dispositivo* Controlador::obterDispositivoPorNome(std::string dispNome){

	for(Dispositivo* d : this->dispositivos){
		if(d->nome==dispNome){
			return d;
		}
	}

	return nullptr; 

}
