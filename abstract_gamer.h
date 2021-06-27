#ifndef ABSGAMER_H
#define ABSGAMER_H
/* abstract gamer - gamers parent class*/
#include <vector>

class AbstractGamer{
private:

public:
	virtual void nextStep(std::vector<std::vector<char>>& map); /* make next step on map */
};

#endif