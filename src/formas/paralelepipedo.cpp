Paralelepipedo::Paralelepipedo(double largura, double altura,double profundidade){
	
	this->dimensoes.push_back(altura);
	this->dimensoes.push_back(largura);
	this->dimensoes.push_back(profundidade);
}

double Paralelepipedo::obterVolumeTotal(){

	return this->dimensoes[0]*this->dimensoes[1]*this->dimensoes[2];

}

double Paralelepipedo::obterVolumeAtual(double altura){

	return altura*this->dimensoes[1]*this->dimensoes[2];

}