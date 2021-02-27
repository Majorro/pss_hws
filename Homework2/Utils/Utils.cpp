#ifndef UTILS
#define UTILS

class Utils
{
public:
    static std::string TypeNameToHumanString(std::string typeIdName) // typeid(type).name()
    {
        std::string tempTypeName = typeIdName;
        auto it = std::find_if(tempTypeName.begin(), tempTypeName.end(), [](char c){ return isalpha(c); });
        tempTypeName = tempTypeName.substr(it-tempTypeName.begin(), tempTypeName.end()-it);
        std::string typeName = std::string(1,tempTypeName[0]);
        for(int i = 1; i < tempTypeName.size(); ++i)
        {
            if(isupper(tempTypeName[i]))
                typeName.push_back(' ');
            typeName.push_back(tempTypeName[i]);
        }
        return typeName;
    }
};

#endif /* UTILS */