#include "repository_of_comments.hpp"

Repository_of_comments::Repository_of_comments()
{
	id_counter = 1;
}

void Repository_of_comments::add_comment(Comment* comment)
{
	comment->set_id(id_counter);
	id_counter++;
	comments.push_back(comment);
}

Comment* Repository_of_comments::search_comment(int comment_id)
{
	for(int i = 0; i < comments.size(); i++)
	{
		if(comments[i]->get_id() == comment_id)
			return comments[i];
	}
	// throw Not_found();
}