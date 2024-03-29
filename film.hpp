#ifndef FILM_H
#define FILM_H

#include <vector>
#include "publisher.hpp"
#include "repository_of_comments.hpp"

const float WEAK_RATE = 5.0;
const float NORMAL_RATE = 8.0;

class Publisher;

class Film
{
public:
	Film(std::string _name, int _year, int _length, int _price, std::string _summary, std::string _director);
	~Film();
	void sold();
	void edit(std::string _name, std::string _year, std::string _length, std::string _price, std::string _summary, std::string _director);
	
	int get_id();
	void set_id(int _id);
	int get_price();
	std::string get_name();
	std::string get_summary();
	std::string get_director();
	int get_year();
	int get_length();
	float get_rate();
	std::vector<Comment*> get_comments();
	Publisher* get_publisher();
	
	
	void add_comment(Comment* comment);
	void delete_comment(int comment_id);
	Comment* search_comment(int comment_id);
	void add_score(float score);
	void calculate_rate();
	int calculate_price();
	
	bool is_weak();
	bool is_normal();
	bool is_good();
	void set_publisher(Publisher* _publisher);
	bool is_not_null(std::string);
    
    void purchased();
    void deleted();
    
    int get_num_of_purchased();
private:
	Publisher* publisher;
	Repository_of_comments* comments;
	int id;
	std::string name;
	int year;
	int length;
	int price;
	std::string summary;
	std::string director;
	std::vector<float> scores;
	int number_of_scores;
	float rate;
    int number_of_purchased;
    bool is_deleted;
};
#endif
