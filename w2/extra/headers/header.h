class Movie
{
    char name[255];
    int year;
    double score;
    int length;

    public:

    void set_name(char* name);
    void set_year(int year);
    void set_score(double score);
    void set_length(int minutes);

    char get_name();
    int get_year();
    double get_score();
    int get_length();

    

};