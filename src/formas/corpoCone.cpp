double CorpoCone::obterVolumeTotal(){

	return (M_PI * this->dimensoes[0] * (this->raioMaior * this->raioMaior + 
										this->raioMaior * this->raioMenor +
										this->raioMenor * this->raioMenor))/3

}

double CorpoCone::obterVolumeAtual(double altura){

	return (M_PI * altura * (this->raioMaior * this->raioMaior + 
							 this->raioMaior * this->raioMenor +
							 this->raioMenor * this->raioMenor))/3;

}