void Dispositivo::iniciar(std::string nNome,std::vector<PORTNUMBER> ps, std::vector<DIRECTION>){
	
	this->nome = nNome;

	for(PORTNUMBER p : ps){

		this->portas.push_back(p);

		//GPIO::setup(this->porta,this->direcao);
	}
}

std::ostream& operator<<(std::ostream& out, Dispositivo* d){

	out << "Nome: " << d->nome << "\t";

	for(PORTNUMBER p : d->portas){
		out << "Porta: " << portNumberToString(p) << "\t";
	}
	
	return out;
}	