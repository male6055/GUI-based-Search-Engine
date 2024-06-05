#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>
#include <fstream>
#include <filesystem>
#include<string>
namespace fs = std::filesystem;

class WebPage {
public:
    std::string url;
    std::string content;
    WebPage(std::string u, std::string c);
    WebPage::~WebPage();

};

class InvertedIndex {
private:
    std::unordered_map<std::string, std::set<int>> index;
public:
    void addPage(int pageId, const std::vector<std::string>& tokens);
    std::set<int> search(const std::string& token) const;

    InvertedIndex::~InvertedIndex();

};

class SearchEngine {
private:
  
    InvertedIndex index;
    std::vector<std::string> tokenize(const std::string& content);
public:
    std::vector<WebPage> pages;

    std::vector<std::string> history;
    void addPageFromFile(const std::string& url, const std::string& filepath);
    void search(const std::string& query, std::vector<std::string >* resultsVector);
    void showHistory(std::vector<std::string>* resultsVector) ;
  //  string getPageContentByUrl(const std::string& url) const;
    void indexDirectory(const std::string& directory);
    SearchEngine::~SearchEngine();
};
