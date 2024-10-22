#include <curl/curl.h>
#include <iostream>
#include <exception>

size_t my_write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    static_cast<std::string*>(userdata)->append((char*) ptr, size * nmemb);
    return nmemb;
}

class Sender{
public:
    Sender(const std::string& url): m_url(url){
        curl = curl_easy_init();
        if(!curl){
            std::cout<<"Error surrounding setting up the socket"<<std::endl;
            throw std::runtime_error(curl_easy_strerror(res));
        }
    }

    void postRequewst(const std::string& data){
        curl_easy_setopt(curl, CURLOPT_URL, m_url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buf);


        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
            throw std::runtime_error(curl_easy_strerror(res));
        }

        std::cout<<"Data recieved: "<<buf<<std::endl;
        buf.clear();
    }


    ~Sender(){
        curl_easy_cleanup(curl);
    }



private:
    const std::string& m_url;
    CURL* curl;
    CURLcode res;
    std::string buf;
};


void testRequests(){
    std::string serverUrl = "http://localhost:8080";

    Sender snd = Sender(serverUrl);

    snd.postRequewst( "register JohnDoe");
    snd.postRequewst("deposit JohnDoe 1000");
    snd.postRequewst("withdraw JohnDoe 500");
}



int main() {
    testRequests();
}
