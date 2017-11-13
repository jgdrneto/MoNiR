Led::Led(std::string nome,PORTNUMBER p){

	this->valor = VALUE::LOW;

	std::vector<PORTNUMBER> ps;

	ps.push_back(p);

	std::vector<DIRECTION> ds;	

	ds.push_back(DIRECTION::OUT);

	this->iniciar(nome,ps,ds);

	#ifdef USANDO_BBB
		GPIO::output(p,VALUE::LOW);
	#endif
}

double Led::acao(){
	
	if(this->valor==VALUE::HIGH){

		#ifdef USANDO_BBB
			GPIO::output(this->portas[0],VALUE::LOW);
		#endif

		this->valor = VALUE::LOW;

		return 0;
	}else{

		#ifdef USANDO_BBB
			GPIO::output(this->portas[0],VALUE::HIGH);
		#endif	
			
		this->valor = VALUE::HIGH;

		return 1;
	}

}

double Led::ligar(){
	if(this->valor==VALUE::LOW){

		this->valor= VALUE::HIGH;
		
		#ifdef USANDO_BBB
			GPIO::output(this->portas[0],VALUE::HIGH);
		#endif
	}

	return this->valor;	
}

double Led::desligar(){
	if(this->valor==VALUE::HIGH){

		this->valor= VALUE::LOW;

		#ifdef USANDO_BBB
			GPIO::output(this->portas[0],VALUE::LOW);
		#endif
	}

	return this->valor;
}
