class OrderedStream {
public:
    vector<string> os;
    int index = 1;
    OrderedStream(int n) {
        os.resize(n+1, "");
    }
    
    vector<string> insert(int idKey, string value) {
        os[idKey] = value;

        vector<string> v;
        for(int i=index; i < os.size(); i++){
            if(os[i] != ""){
                v.push_back(os[i]);
            }else{
                index = i;
                break;
            }
        }
        return v;
    }
};
