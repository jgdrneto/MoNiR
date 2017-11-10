Medicao::Medicao(Data& nData,double nVolumeAtual){
	this->data = nData;
	this->volumeAtual = nVolumeAtual;
}

std::ostream& operator<<(std::ostream& out, Medicao& m){
	out << "Data: " << m.data << " Volume atual: " << m.volumeAtual; 
}