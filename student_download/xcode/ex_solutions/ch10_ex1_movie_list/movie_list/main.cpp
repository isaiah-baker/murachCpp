#include <iostream>
#include <fstream>
#include <sstream> 
#include <iomanip>
#include <string>
#include <list>

using namespace std;

struct Movie {
    string title = "";
    unsigned int year = 0;
    unsigned int stars = 0;
    bool equals(Movie&);              // member function declaration
};

// member function definition
bool Movie::equals(Movie& to_compare) {
    return (title == to_compare.title && year == to_compare.year);
}

const string movies_file = "movies.txt";

string get_fulll_path() {
    // set a full path to the correct directory
    const char* home = getenv("HOME");
    string user_home = "";
    if (home) {
        user_home = home;
    }
    else {
        // if home isn't found, edit 'username' so it's correct for your system
        user_home = "/Users/username";
    }
    string file_path = "/Documents/murach/cpp/files/";
    return user_home + file_path;
}

list<Movie> read_movies_from_file() {
    list<Movie> movies;

    ifstream input_file(get_fulll_path() + movies_file);
    if (input_file) {    // if file opened successfully...
        Movie movie;
        string line;
        while (getline(input_file, line)) {
            stringstream ss(line);

            getline(ss, movie.title, '\t');     // get title
            ss >> movie.year >> movie.stars;    // get year and stars
            movies.push_back(movie);            // add movie to vector
        }
        input_file.close();
    }
    return movies;
}

void write_movies_to_file(const list<Movie>& movies) {
    ofstream output_file(get_fulll_path() + movies_file);
    if (output_file) {     // if file opened successfully...
        for (Movie movie : movies) {
            output_file << movie.title << '\t' 
                << movie.year << '\t'
                << movie.stars << '\n';
        }
        output_file.close();
    }
}

void view_movies(const list<Movie>& movies) {
    int col_width = 8;
    cout << left
        << setw(col_width / 2) << " "
        << setw(col_width * 4) << "TITLE"
        << setw(col_width) << "YEAR"
        << setw(col_width) << "STARS" << endl;

    int number = 1;
    for (Movie movie : movies) {
        cout << setw(col_width / 2) << number
            << setw(col_width * 4) << movie.title
            << setw(col_width) << movie.year
            << setw(col_width) << movie.stars << endl;
        ++number;
    }
    cout << endl;
}

Movie get_movie() {
    Movie movie;
    cout << "Title: ";
    cin.ignore(1000, '\n');
    getline(cin, movie.title);
    cout << "Year: ";
    cin >> movie.year;
    cout << "Stars (1-5): ";
    cin >> movie.stars;
    return movie;
}

void add_movie(list<Movie>& movies) {
    Movie movie = get_movie();

    // check if movie already exists
    bool already_exists = false;
    for (Movie& m : movies) {
        if (m.equals(movie)) {
            already_exists = true;
            break;
        }
    }

    if (already_exists) {
        cout << movie.title << " already exists.\n\n";
    }
    else {
        movies.push_back(movie);
        write_movies_to_file(movies);
        cout << movie.title << " was added.\n\n";
    }
}

int get_movie_number(const list<Movie>& movies) {
	cin.ignore(1000, '\n');
	int number;
    while (true) {
        cout << "Number: ";
        cin >> number;
        if (number > 0 && number <= movies.size()) {
            return number;
        }
        else {
            cout << "Invalid movie number. Try again.\n";
        }
    }
}

void delete_movie(list<Movie>& movies) {
    int number = get_movie_number(movies);

	auto iter = movies.begin();
	for (int i = 1; i < number; ++i) {
		++iter;
	}
	Movie movie = *iter;
	movies.erase(iter);

    write_movies_to_file(movies);
    cout << movie.title << " was deleted.\n\n";
}

void modify_movie(list<Movie>& movies) {
	int number = get_movie_number(movies);

	auto iter = movies.begin();
	for (int i = 1; i < number; ++i) {
		++iter;
	}
	Movie& movie = *iter;

	cout << "Enter new number of stars (1-5) for " << movie.title << ": ";
	cin >> movie.stars;
	// update movie list

	write_movies_to_file(movies);
	cout << movie.title << " was updated.\n\n";
}

void display_menu() {
    cout << "COMMANDS\n"
        << "v - View movie list\n"
        << "a - Add a movie\n"
        << "d - Delete a movie\n"
		<< "m - Modify a movie\n"
        << "x - Exit\n\n";
}

int main() {
    cout << "The Movie List program\n\n";
    display_menu();
    list<Movie> movies = read_movies_from_file();
    char command = 'v';
    while (command != 'x') {
        cout << "Command: ";
        cin >> command;
        switch (command) {
        case 'v':
            view_movies(movies);
            break;
        case 'a':
            add_movie(movies);
            break;
        case 'd':
            delete_movie(movies);
            break;
		case 'm':
			modify_movie(movies);
			break;
        case 'x':
            cout << "Bye!\n\n";
            break;
        default:
            cout << "Not a valid command. Please try again.\n\n";
            break;
        }
    }
}
