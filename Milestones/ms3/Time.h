namespace seneca {
    class Time {
        unsigned int m_minutes;

    public:
        Time(unsigned int min = 0);
        Time& reset();
        Time& operator-=(const Time& D);
        Time operator-(const Time& T) const;
        Time& operator*=(int val);
        operator unsigned int() const;

        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);

        friend std::ostream& operator<<(std::ostream& ostr, const Time& time);
        friend std::istream& operator>>(std::istream& istr, Time& time);
    };
}