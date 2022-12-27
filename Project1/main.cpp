
#include<iostream>
#include<vector>
#include<deque>
#include"Competiotor.h"
#include"Obstacle.h"


using namespace std;

void DeleteCompetitor(deque<Competitor*>& CDeq, Competitor* obj);

int main() {
	deque<Competitor*>deqCompetotor;
	vector<Obstacle*>vectObstacle;
	deqCompetotor.push_back(new Human("Human"));
	deqCompetotor.push_back(new Cat("Cat"));
	deqCompetotor.push_back(new Robot("Robot"));

	for (int i = 0; i < 2; i++) {
		vectObstacle.push_back(new Wall(i));
	}
	for (int i = 1000; i < 4000; i += 1000) {
		vectObstacle.push_back(new Treadmill(i));
	}

	for (int i = 0; i < (int)vectObstacle.size() && deqCompetotor.size()>0; i++) {
		for (int j = 0; j < (int)deqCompetotor.size(); j++) {
			bool hasCoped = vectObstacle[i]->Cope(deqCompetotor[j]);
			if (!hasCoped) {
				DeleteCompetitor(deqCompetotor, deqCompetotor[j]);
				j--;
			}
		}
		cout << "---------------------------------------\n";
	}

	if (deqCompetotor.size() > 0) {
		for (int i = 0; i < (int)deqCompetotor.size(); i++) {
			cout << deqCompetotor[i]->GetName().c_str() << " won.\n";
		}
	}
	else {
		cout << "There is no winner.";
	}

	for (int i = 0; i < (int)deqCompetotor.size(); i++) {
		delete deqCompetotor[i];
	}
	for (int i = 0; i < (int)vectObstacle.size(); i++) {
		delete vectObstacle[i];
	}

}

void DeleteCompetitor(deque<Competitor*>& CDeq, Competitor* obj) {
	deque<Competitor*>::iterator iter = CDeq.begin();
	for (; strcmp((*iter)->GetName().c_str(), obj->GetName().c_str()) != 0; iter++) {};
	CDeq.erase(iter);
}