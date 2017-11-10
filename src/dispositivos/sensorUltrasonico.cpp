SensorUltrasonico::SensorUltrasonico(std::string nome,PORTNUMBER p1,PORTNUMBER p2){
	
	std::vector<PORTNUMBER> ps;

	ps.push_back(p1);
	ps.push_back(p2);

	std::vector<DIRECTION> ds;	

	ds.push_back(DIRECTION::OUT);
	ds.push_back(DIRECTION::IN);

	this->iniciar(nome,ps,ds);
	
}

double SensorUltrasonico::acao(){
	return 0;
}