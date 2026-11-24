#include <memory>
#include <string>
#include <iostream>

class HTTPConnection
{
public:

    HTTPConnection(const std::string& hostName, int portNo)
        : host(hostName), port(portNo)
    {
        std::cout << "HTTP Connection for host: "
            << host << " on port: " << port
            << " created" << std::endl;
    }

    ~HTTPConnection()
    {
        std::cout << "Connection for host: "
            << host << " on port: " << port
            << " destroyed" << std::endl;
    }

    void download()
    {
        std::cout << "(Downloading from website) " << host << std::endl;
    }

    void disconnect();
    void sendRequest(const std::string& request);
    std::string receiveResponse();

private:

    int port;
    std::string host;
};

int main(int argc, char* argv[])
{
    
        // A dumb pointer
        // Manually delete the pointer
        HTTPConnection* connection1 = new HTTPConnection("www.google.com", 8000);
        connection1->download();
        (*connection1).download();
        delete connection1;
        connection1 = nullptr;
       
        std::cout << std::endl;
        {
            // Create a smart pointer (unique_ptr)
            std::unique_ptr<HTTPConnection> connection(new HTTPConnection("www.github.com", 8081));

            std::cout << std::endl;

            std::unique_ptr<HTTPConnection>connection2 = std::make_unique<HTTPConnection>("www.github.com", 8000);

            std::cout << std::endl;

            auto connection4 = std::move(connection2);
            // Call the download method through the new owner
            connection4->download();
        }
        std::cout << std::endl;

        //shared pointer example
        std::shared_ptr<HTTPConnection>pConnection1(new HTTPConnection("www.yahoo.com", 443));
        std::cout << pConnection1.get() << std::endl;

        std::shared_ptr<HTTPConnection> pconnection5 = pConnection1;
        pconnection5->download();
        auto pConnection2 = pConnection1;
        std::shared_ptr<HTTPConnection>pconnection2 = std::make_shared<HTTPConnection>("www.facebook.com", 7000);

        std::cout << pConnection2.use_count() << std::endl;
        std::cout << pconnection5.get() << std::endl;
            
 
        return 0;
}