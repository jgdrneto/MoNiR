Reservatorio* Leitor::ler(std::string nomeArquivo){

	Reservatorio* reservatorio = nullptr;

	nlohmann::json j;

	//std::cout << nomeArquivo << std::endl;

	std::ifstream i(nomeArquivo);

	if(!i.is_open()){
		return nullptr;
	}else{

		i >> j;	

		Forma* forma = nullptr;

		if (j["RESERVATORIO"]["TIPO"] == "CILINDRO"){

			forma = new Cilindro(j["RESERVATORIO"]["RAIO"],
								 j["RESERVATORIO"]["ALTURA"]);

		}else if (j["RESERVATORIO"]["TIPO"] == "PARALELEPIPEDO"){

			forma = new Paralelepipedo(j["RESERVATORIO"]["LARGURA"],
							           j["RESERVATORIO"]["ALTURA"],
							           j["RESERVATORIO"]["PROFUNDIDADE"]);

		}else if (j["RESERVATORIO"]["TIPO"] == "CORPO_CONE"){

			forma = new CorpoCone(j["RESERVATORIO"]["RAIOMENOR"],
							      j["RESERVATORIO"]["RAIOMAIOR"],
							      j["RESERVATORIO"]["ALTURA"]);

		}else{
			return reservatorio;	
		}

		return new Reservatorio(forma);

	}
}