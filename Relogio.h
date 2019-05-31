#ifndef RELOGIO_H
#define RELOGIO_H

#include <time.h>
#include <stdlib.h>

class Relogio
{
public:
	Relogio(int seg, int min, int hora);
	Relogio();
	~Relogio();
	void resetHora();
	int getSeg() const;
	int getMin() const;
	int getHora() const;
	Relogio &setSeg(int seg);
	Relogio &setMin(int min);
	Relogio &setHora(int hora);
private:
	time_t hora;
	struct tm *infoHora;
	
};

#endif