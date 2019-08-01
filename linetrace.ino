int linetrace(){
	int diff,Lpower,Rpower;
	diff = analogRead(phtLr)-analogRead(phtRl);
	Lpower = basic_motorpower+(dif*p);
	Rpower = basic_motorpower+(dif*p);
	if(analogRead(phtC)>limen){
		if(analogRead(phtLl)>analogRead(phtRr)){
			Lpower+=boostpower_corner;
			Rpower-=boostpower_corner;
		}else{
			Lpower-=boostpower_corner;
			Rpower+=boostpower_corner;
		}
	MOVE(Lpower,Rpower);
	}
}
