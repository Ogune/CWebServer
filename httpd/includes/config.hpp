/* -- config.hpp -- */ 

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "includes.hpp"

/* 
  * Hadchi kaykhlik tsta3mel les fonctions ou les classes dyal std (bhal cout, string) 
  * bla ma tzid 'std::'.  Mzyan f les petits projets, walakin f les grands projets yqder
  *  ydir clash m3a les noms dyal les variables dyalk. Ila bghiti code mtnaddem w professional,
  *  khassak tsta3mel 'std::' directement.
*/
using namespace std;

/* ========================== STRUCTURES =============================== */
struct Location
{
    bool autoindex;
    string root;
    string path;
    string redirection_return;
    string upload_path;
    vector<string> allow_methods;
    vector<string> index;
    map<string, string> cgi_path;
    
    Location() : autoindex(false) {}
};

/* ========================== MAIN CLASS ================================ */
class ServerConfiguration
{
    public:
	ServerConfiguration(): maxBodySize(-1) {}

	/* --------------- Parameters & Data Members ----------------- */
	vector<string> ports;
        string host;
        string bodySize;
        ssize_t maxBodySize;
        vector<string> serverNames;
        map<int, string> errorPages;
        map<string, Location> locations;

        /* --------------- Member Functions ------------------------- */
	string getErrorPage(string code);
        string getLocations(string path);
        ServerConfiguration getServerConfiguration(const string &host, string &port, string &ip);
};

#endif /* ayeh ayeh, config.hpp */
