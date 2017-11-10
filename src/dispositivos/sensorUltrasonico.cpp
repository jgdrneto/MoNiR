SensorUltrasonico::SensorUltrasonico(std::string nome,PORTNUMBER p1,PORTNUMBER p2){
	
	std::vector<PORTNUMBER> ps;

	ps.push_back(p1);
	ps.push_back(p2);

	std::vector<DIRECTION> ds;	

	ds.push_back(DIRECTION::OUT);
	ds.push_back(DIRECTION::IN);

	this->iniciar(nome,ps,ds);

	this->valor=0;

}

//Retorna valor em decímetros
double SensorUltrasonico::acao(){
	
	double result = sin(this->valor);

	this->valor +=0.1; 
	
	//Garantindo apenas valores positivos
	if(result<0){
		result=(-1)*result;
	}

	//Altura máxima de 5 decimetros
	return 5*result;
}