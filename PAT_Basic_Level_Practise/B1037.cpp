#include <cstdio>
#include <algorithm>

struct Money;
void swap(Money &m1, Money &m2);
struct Money{
	int galleon, sickle, knut;
	bool sign;
	Money() : sign(true) {}
	Money &operator - (Money &m){
		if(*this < m){
			swap(*this, m);
			sign = false;
		}
		if(knut < m.knut){
			--sickle;
			knut += 29;
		}
		knut -= m.knut;
		if(sickle < m.sickle){
			--galleon;
			sickle += 17;
		}
		sickle -= m.sickle;
		galleon -= m.galleon;
		return *this;
	}
	bool operator < (const Money &m) const{
		if(galleon != m.galleon) return galleon < m.galleon;
		else if(sickle != m.sickle) return sickle < m.sickle;
		else return knut < m.knut;
	}
	void print() const{
		if(sign == false)
			printf("-");
		printf("%d.%d.%d", galleon, sickle, knut);
	}
};

void swap(Money &m1, Money &m2){
	std::swap(m1.galleon, m2.galleon);
	std::swap(m1.sickle, m2.sickle);
	std::swap(m1.knut, m2.knut);
}

int main(){
	Money p, a;
	scanf("%d.%d.%d %d.%d.%d", &p.galleon, &p.sickle, &p.knut, &a.galleon, &a.sickle, &a.knut);
	(a - p).print();
	return 0;
}