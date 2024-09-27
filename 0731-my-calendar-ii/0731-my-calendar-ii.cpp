class MyCalendarTwo {
public:
    // Store the number of bookings at each point.
    map<int, int> bookingCount;
    // The maximum number of overlapped bookings allowed.
    int maxOverlappedBooking;

    MyCalendarTwo() { maxOverlappedBooking = 2; }

    bool book(int start, int end) {
        // Increase and decrease the booking count at the start and end
        // respectively.
        bookingCount[start]++;
        bookingCount[end]--;

        int overlappedBooking = 0;
        // Find the prefix sum.
        for (pair<int, int> bookings : bookingCount) {
            overlappedBooking += bookings.second;

            // If the number of bookings is more than 2, return false.
            // Also roll back the counts for this booking as we won't add it.
            if (overlappedBooking > maxOverlappedBooking) {
                bookingCount[start]--;
                bookingCount[end]++;

                // Remove the entries from the map to avoid unnecessary
                // iteration.
                if (bookingCount[start] == 0) {
                    bookingCount.erase(start);
                }
                if (bookingCount[end] == 0) {
                    bookingCount.erase(end);
                }

                return false;
            }
        }

        return true;
    }
};