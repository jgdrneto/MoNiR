void Controlador::salvarRelatorio(std::string arquivo,std::vector<Medicao>& medicoes){
	
	nlohmann::json j;

	std::ifstream i(arquivo);
		
	if(i.is_open() && i.peek() != std::ifstream::traits_type::eof()){
    	i >> j;
	}

    i.close();
	
	for(Medicao m: medicoes){

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