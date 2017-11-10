double Retangulo::obterVolumeTotal(){

	return this->dimensoes[0]*this->dimensoes[1]*this->dimensoes[2];

}

double Retangulo::obterVolumeAtual(double altura){

	return altura*this->dimensoes[1]*this->dimensoes[2];

}