#include "SearchEngine.h"

using namespace std;

// WebPage class implementation
WebPage::WebPage(string u, string c) : url(u), content(c) {}

// InvertedIndex class implementation
void InvertedIndex::addPage(int pageId, const vector<string>& tokens) {
    for (const string& token : tokens) {
        index[token].insert(pageId);
    }
}

set<int> InvertedIndex::search(const string& token) const {
    if (index.find(token) != index.end()) {
        return index.at(token);
    }
    return set<int>();
}

// SearchEngine class implementation
vector<string> SearchEngine::tokenize(const string& content) {
    vector<string> tokens;
    string token;
    for (char ch : content) {
        if (ch == ' ') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
        else {
            token += ch;
        }
    }
    if (!token.empty()) tokens.push_back(token);
    return tokens;
}

void SearchEngine::addPageFromFile(const string& url, const string& filepath) {
    ifstream file(filepath);
    if (!file.is_open()) {
        cerr << "Error: Failed to open file " << filepath << endl;
        return;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();

    file.close();

    pages.push_back(WebPage(url, content));
    int pageId = pages.size() - 1;
    index.addPage(pageId, tokenize(content));
}

void SearchEngine::search(const string& query, vector<string>*resultsVector) {

    history.push_back(query);
    istringstream iss(query);
    string word;
    bool foundAny = false;

    while (iss >> word) {
        auto results = index.search(word);
        if (results.empty()) {
          //  cout << "No results found for: " << word << endl;
        //    resultsVector->push_back("No results found");
        }
        else {
            foundAny = true;
            cout << "Results for: " << word << endl;
            for (int pageId : results) {
                cout << " - " << pages[pageId].url << endl;
                resultsVector->push_back(pages[pageId].url);
            }
        }
    }

    if (!foundAny) {
        cout << "No documents contain the queried words." << endl;
        //resultsVector->push_back("No results found for: " + word);
    }
}

void SearchEngine::showHistory(vector<string>* resultsVector)  {
    cout << "Search History:\n";
    for (const string& q : history) {
        cout << q << endl;
        resultsVector->push_back(q);
    }
}

void SearchEngine::indexDirectory(const string& directory) {
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            addPageFromFile(entry.path().string(), entry.path().string());
        }
    }
}
WebPage::~WebPage() {}

InvertedIndex::~InvertedIndex() {}

SearchEngine::~SearchEngine() {}
