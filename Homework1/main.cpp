// #define DEBUG

#include<iostream>
#include<fstream>
#include<vector>

void split(std::string& text, std::vector<std::string>& result)
{
    int len = text.size();
    std::string buf = "";
    for(int i = 0; i<len; ++i)
    {
        buf.push_back(text[i]);
        if(text[i]=='.')
        {
            result.push_back(buf);
            buf = "";
            ++i;
        }
    }
    if(!buf.empty()) result.push_back(buf);
}

void search(std::vector<std::string>& sentences, std::string& word, std::vector<std::string>& out)
{
    for(auto sentence : sentences)
    {
        std::string temp_sentence = sentence;
        int pos = 0;
        bool has_word = 0;
        while((pos = temp_sentence.find(word, pos)) != std::string::npos) //method find returns std::string::npos when substring is not found
        {
            if(pos && temp_sentence[pos-1] != ' ' ||
               temp_sentence[pos+word.size()] != ' ' &&
               temp_sentence[pos+word.size()] != '.') //checking that word is not substring of other word
            {
                ++pos;
                continue;
            }
            has_word = 1;
            for(int i = pos; temp_sentence[i] != ' ' && temp_sentence[i] != '.'; ++i) //uppercasing found word
                temp_sentence[i] = toupper(temp_sentence[i]);
        }
        if(has_word)
            out.push_back(temp_sentence);
    }
}

int main()
{
#ifdef DEBUG
    std::ifstream in("H:\\repos\\pss_hws\\Homework1\\in.txt");
    std::ofstream out("H:\\repos\\pss_hws\\Homework1\\out.txt");
#else
    std::ifstream in("in.txt");
    std::ofstream out("out.txt");
#endif

    std::string text;
    std::vector<std::string> sentences;

    getline(in, text);
    split(text, sentences);
    
    int queries_number;
    in >> queries_number;
    while(queries_number--)
    {
        std::string queried_word;
        std::vector<std::string> found_sentences;
        in >> queried_word;
        search(sentences, queried_word, found_sentences);
        out << found_sentences.size() << std::endl;
        for(auto sentence : found_sentences) out << sentence << std::endl;
    }

    return 0;
}