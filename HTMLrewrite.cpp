#include "main.h"
#include "Gamer.h"

void HTMLwrite ( Gamer** gamer, int gamersCount, map<wchar_t, int>* cardsMap ) {
	ofstream outFile ( FILE_RW );

	outFile << "<!DOCTYPE html>" << endl;
	outFile << "<html lang=\"ru\">" << endl;
	outFile << "<head>" << endl;
	outFile << " <meta charset=\"UTF-8\">" << endl;
	outFile << "<title>Black Jack game</title>" << endl;
	outFile << "<style>" << endl;
	outFile << "h1 {text-align: center;}" << endl;
	outFile << ".casino {display: flex;flex-wrap: wrap;justify-content: center;}" << endl;
	outFile << ".gamer {text-align: center;font-size: 48px;padding: 10px;margin: 10px;border-style: dashed;}" << endl;
	outFile << "h2 {font-size: 38px;}" << endl;
	outFile << ".hands {font-size: 108px;line-height: 1em; margin: 0;}" << endl;
	outFile << "</style>" << endl;
	outFile << "</head>" << endl;
	outFile << "<body>" << endl;

	map <wchar_t, int> :: iterator it=cardsMap->begin();
	for ( int i = 0; it != cardsMap->end(); i++, it++ ) {
		outFile << "<p>&#" << it->first << "  " << it->second << "<p>" << endl;
	}

	outFile << "<h1>Игра BlackJack (Очко)</h1>" << endl;
	outFile << "<div class=\"casino\">" << endl;

	// Вскрытие
	pair<wchar_t, wchar_t> gamerCards;

	for ( int i = 0; i < gamersCount; i++ ) {
		gamerCards = gamer[i]->getCards();

		outFile << "<div class=\"gamer\">" << endl;
		outFile << "<h2>" << gamer[i]->getName()->c_str() << "</h2>" << endl;
		outFile << "<div>" << endl;
		outFile << "<p class=\"hands\">&#" << gamerCards.first << ";&#" << gamerCards.second << ";<p>" << endl;
		outFile << "<p>" << gamer[i]->pointCount() << "<p>" << endl;
		outFile << "</div>" << endl;
		outFile << "</div>" << endl;
	}

	outFile << "</div>\n</body>\n</html>" << endl;
	outFile.close();
}

void HTMLwrite ( Gamer** gamer, int gamersCount ) {
	ofstream outFile ( FILE_RW );

	outFile << "<!DOCTYPE html>" << endl;
	outFile << "<html lang=\"ru\">" << endl;
	outFile << "<head>" << endl;
	outFile << " <meta charset=\"UTF-8\">" << endl;
	outFile << "<title>Black Jack game</title>" << endl;
	outFile << "<style>" << endl;
	outFile << "h1 {text-align: center;}" << endl;
	outFile << ".casino {display: flex;flex-wrap: wrap;justify-content: center;}" << endl;
	outFile << ".gamer {text-align: center;font-size: 48px;padding: 10px;margin: 10px;border-style: dashed;}" << endl;
	outFile << "h2 {font-size: 38px;}" << endl;
	outFile << ".hands {font-size: 108px;line-height: 1em; margin: 0;}" << endl;
	outFile << "</style>" << endl;
	outFile << "</head>" << endl;
	outFile << "<body>" << endl;
	outFile << "<h1>Игра BlackJack (Очко)</h1>" << endl;
	outFile << "<div class=\"casino\">" << endl;

	// Вскрытие
	pair<wchar_t, wchar_t> gamerCards;
	string* winner;
	int temp = 0;

	for ( int i = 0; i < gamersCount; i++ ) {
		gamerCards = gamer[i]->getCards();

		outFile << "<div class=\"gamer\">" << endl;
		outFile << "<h2>" << gamer[i]->getName()->c_str() << "</h2>" << endl;
		outFile << "<div>" << endl;
		outFile << "<p class=\"hands\">&#" << gamerCards.first << ";&#" << gamerCards.second << ";<p>" << endl;
		outFile << "<p>" << gamer[i]->pointCount() << "<p>" << endl;
		outFile << "</div>" << endl;
		outFile << "</div>" << endl;

		if ( temp < gamer[i]->pointCount() ) {
			temp = gamer[i]->pointCount();
			winner = gamer[i]->getName();
		}
	}

	outFile << "</div>\n<h2>" << endl;
	outFile << "\n\nБанк взял ";
	outFile << winner->c_str();
	outFile << " c ";
	outFile << temp;
	outFile << "-ю очками\n";

	outFile << "<h2>\n</body>\n</html>" << endl;
	outFile.close();
}


