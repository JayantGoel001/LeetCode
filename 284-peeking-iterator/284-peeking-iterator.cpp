class PeekingIterator : public Iterator{
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums){}

    int peek(){
        return Iterator(*this).next();
    }

    int next(){
        return Iterator::next();
    }

    bool hasNext() const{
        return Iterator::hasNext();
    }
};