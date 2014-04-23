Led::Led(std::string nome,PORTNUMBER p, bool usarBBB){

	this->valor = VALUE::LOW;

	std::vector<PORTNUMBER> ps;

	ps.push_back(p);

	std::vector<DIRECTION> ds;	

	ds.push_back(DIRECTION::OUT);

	this->iniciar(nome,ps,ds,usarBBB);
	
	if(this->usarBBB){
		GPIO::output(p,VALUE::LOW);
	}
	
}

double Led::acao(){
	
	if(this->valor==VALUE::HIGH){
		
		if(this->usarBBB){
			GPIO::output(this->portas[0],VALUE::LOW);
		}		
		this->valor = VALUE::LOW;

		return 0;
	}else{

		if(this->usarBBB){	
			GPIO::output(this->portas[0],VALUE::HIGH);
		}		
		this->valor = VALUE::HIGH;

		return 1;
	}

}

double Led::ligar(){
	if(this->valor==VALUE::LOW){

		this->valor=this->acao();
		
	}

	return this->valor;	
}

double Led::desligar(){
	if(this->valor==VALUE::HIGH){

		this->valor=this->acao();
	}

	return this->valor;
}
