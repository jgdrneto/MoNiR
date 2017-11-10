Led::Led(std::string nome,PORTNUMBER p){

	this->valor = VALUE::LOW;

	std::vector<PORTNUMBER> ps;

	ps.push_back(p);

	std::vector<DIRECTION> ds;	

	ds.push_back(DIRECTION::OUT);

	this->iniciar(nome,ps,ds);

	//GPIO::output(this->p,VALUE::LOW);
}

double Led::acao(){
	
	if(this->valor==VALUE::HIGH){

		//GPIO::output(this->p,VALUE::LOW);

		this->valor = VALUE::LOW;

		return 0;
	}else{

		//GPIO::output(this->p,VALUE::HIGH);

		this->valor = VALUE::HIGH;

		return 1;
	}

}