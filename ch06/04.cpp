// 영화 정보 저장

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie {
private :
	string title; //제목
	double rating; //평점
public :
	Movie(string t = "", double r = 0.0) { title = t; rating = r; }
	void print_movie() {
		cout << title << " : " << rating << endl;
	}
};

int main(void) {
	vector<Movie> movies;
	movies.push_back(Movie("titinic", 9.9));
	movies.push_back(Movie("gone with the wind", 9.6));
	movies.push_back(Movie("terminator", 9.7));

	for (auto& e : movies)
		e.print_movie();
	
	return 0;
}