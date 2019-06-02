#include "handlers.hpp"

using namespace std;

Response *RandomNumberHandler::callback(Request *req) {
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    string body;
    body += "<!DOCTYPE html>";
    body += "<html>";
    body += "<body style=\"text-align: center;\">";
    body += "<h1>AP HTTP</h1>";
    body += "<p>";
    body += "a random number in [1, 10] is: ";
    body += to_string(rand() % 10 + 1);
    body += "</p>";
    body += "<p>";
    body += "SeddionId: ";
    body += req->getSessionId();
    body += "</p>";
    body += "</body>";
    body += "</html>";
    res->setBody(body);
    return res;
}

Response *LoginHandler::callback(Request *req) {
    string username = req->getBodyParam("username");
    string password = req->getBodyParam("password");
    if (username == "root")
        throw Server::Exception("Remote root access has been disabled.");
    Response *res = Response::redirect("../Phase3/home.html");
    web->login(username, password);
    res->setSessionId(to_string(web->get_id_of_login_user()));
    return res;
}

Response *SignupHandler::callback(Request *req)
{
    string username = req->getBodyParam("username");
    string password = req->getBodyParam("password");
    string repass = req->getBodyParam("repassword");
    int age = stoi(req->getBodyParam("age"));
    string email = req->getBodyParam("email");
    bool is_publisher = stoi(req->getBodyParam("is_publisher"));
    if(password != repass)
        throw Server::Exception("Please enter your password again.");
    web->signup(username, password, age, email, is_publisher);
    Response *res = Response::redirect("../Phase3/home.html");
    res->setSessionId(to_string(web->get_id_of_login_user()));
    return res;
}

Response *UploadHandler::callback(Request *req) {
    string name = req->getBodyParam("file_name");
    string file = req->getBodyParam("file");
    cout << name << " (" << file.size() << "B):\n" << file << endl;
    Response *res = Response::redirect("/");
    return res;
}

ColorHandler::ColorHandler(string filePath) : TemplateHandler(filePath) {}

map<string, string> ColorHandler::handle(Request *req) {
    map<string, string> context;
    string newName = "I am " + req->getQueryParam("name");
    context["name"] = newName;
    context["color"] = req->getQueryParam("color");
    return context;
}