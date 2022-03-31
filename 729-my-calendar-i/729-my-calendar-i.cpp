class MyCalendar {
    map<int, int> books;
public:
    bool book(int s, int e) {
        auto next = books.lower_bound(s);
        if (next != books.end() && next->first < e) return false;
        if (next != books.begin() && s < (--next)->second) return false;
        books[s] = e;
        return true;
    }
};