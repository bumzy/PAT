#include <cstdio>
#include <cstring>
//using namespace std;

struct persion{
	char name[8];
	int year;
	int month;
	int day;
	bool operator <= (const persion &p) const{
		if(year < p.year) return true;
		else if(year == p.year && month < p.month) return true;
		else if(year == p.year && month == p.month && day <= p.day) return true;
		return false;
	}
	bool operator >= (const persion &p) const{
		if(year > p.year) return true;
		else if(year == p.year && month > p.month) return true;
		else if(year == p.year && month == p.month && day >= p.day) return true;
		return false;
	}
	persion &operator = (const persion &p){
		if(this == &p)
			return *this;
		strcpy(name, p.name);
		year = p.year;
		month = p.month;
		day = p.day;
		return *this;
	}
};

int main(){
	int n;
	persion tmp, max, min, low_bound, up_bound;

	up_bound.year = 2014; low_bound.year = 1814;
	up_bound.month = low_bound.month = 9;
	up_bound.day = low_bound.day = 6;

	max = low_bound;
	min = up_bound;

	scanf("%d", &n);
	int valid_count = 0;
	while(n--){
		scanf("%s %d/%d/%d", tmp.name, &tmp.year, &tmp.month, &tmp.day);
		if(tmp >= low_bound && tmp <= up_bound){
			++valid_count;
			if(tmp >= max)
				max = tmp;
			if(tmp <= min)
				min = tmp;
		}
	}
	printf("%d", valid_count);
	if(valid_count > 0){
		printf(" %s", min.name);
		printf(" %s", max.name);
	}
	return 0;
}