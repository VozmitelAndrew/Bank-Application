#include <curl/curl.h>
#include <iostream>

size_t my_write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    static_cast<std::string*>(userdata)->append((char*) ptr, size * nmemb);
    return nmemb;
}

void sendRequest(const std::string& url, const std::string& requestType, const std::string& data) {
    CURL* curl;
    CURLcode res;
    std::string buf;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());


        if (requestType == "POST") {
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buf);
        }

        res = curl_easy_perform(curl);
        std::cout<<" LOOOL I love " << buf<<" you LOOOL "<<std::endl;

        if (res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }
}

int main() {
    std::string serverUrl = "http://localhost:8080";

    // Регистрация пользователя
    sendRequest(serverUrl, "POST", "register JohnDoe");

    // Пополнение счета
    sendRequest(serverUrl, "POST", "deposit JohnDoe 1000");

    // Снятие со счета
    sendRequest(serverUrl, "POST", "withdraw JohnDoe 500");

    return 0;
}
