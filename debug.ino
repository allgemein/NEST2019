void debug_pht(){

	int valLl = analogRead(phtLl);
	int valLr = analogRead(phtLr);
	int valC = analogRead(phtC);
	int valRl = analogRead(phtRl);
	int valRr = analogRead(phtRr);

	sprintf(str,"pht: %4d%4d%4d%4d%4d",valLl,valLr,valC,valRl,valRr);
	Serial.println(str);

	}

void debug_motor(){

	MOVE(255,255);
	delay(750);
	MOVE(-255,-255);
	delay(750);
	MOVE(255,0);
	delay(750);
	MOVE(255,0);
	delay(750);
	MOVE(0,255);
	delay(750);
	MOVE(0,0);
	delay(250);

	}

