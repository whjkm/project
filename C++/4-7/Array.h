class Array
{
    public:
        Array(int len);
        ~Array();
        Array *setLen(int len);
        int getLen();
        Array *printInfo();
    private:
        //int m_iLen;
        int len;
};

