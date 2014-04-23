void Dispositivo::iniciar(std::string nNome,std::vector<PORTNUMBER> ps, std::vector<DIRECTION> ds){
	
	this->nome = nNome;

	for(unsigned int i=0;i<ps.size();i++){

		this->portas.push_back(ps[i]);

		GPIO::setup(ps[i],ds[i]);
	}
}

std::ostream& operator<<(std::ostream& out, Dispositivo* d){

	out << "Nome: " << d->nome << "\t";

	for(PORTNUMBER p : d->portas){
		out << "Porta: " << portNumberToString(p) << "\t";
	}
	
	return out;
}	
