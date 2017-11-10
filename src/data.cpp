Data::Data(){
	//NULO
}

Data::Data(Tipo hora,Tipo min,Tipo seg,Tipo dia ,Tipo mes,Tipo ano){
	this->v[Data::DIA] = dia;
	this->v[Data::MES] = mes;
	this->v[Data::ANO] = ano;
	this->v[Data::HORA] = hora;
	this->v[Data::MINUTO] = min;
	this->v[Data::SEGUNDO] = seg;
}

Data& Data::obterDataAtual(){
	time_t t = time(0);

	struct tm* now = localtime( &t );

	return *(new Data(now->tm_hour,now->tm_min,now->tm_sec,now->tm_mday,now->tm_mon+1,now->tm_year+1900));	
}

Data::Tipo& Data::operator[](std::size_t idx){
	return this->v[idx];
}
 
std::ostream& operator<<(std::ostream& out, Data& d){

	std::string data[6]; 

	for(int i =0;i<6;i++){
		if(d[i]<10){
			data[i] = "0"+std::to_string(d[i]);
		}else{
			data[i] = std::to_string(d[i]);
		}
	}

   	return out <<  data[Data::HORA] << ":" << data[Data::MINUTO] << ":" << data[Data::SEGUNDO] << " " << data[Data::DIA] << "/" << data[Data::MES] << "/" << data[Data::ANO];
}

