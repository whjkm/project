
class Coordinate
{
    public:
        Coordinate(int x,int y);
        ~Coordinate();
        int getX() const;
        void setX(int x);
        int getY() const;
        void setY(int y);
    private:
        int m_iX;
        int m_iY;
};

