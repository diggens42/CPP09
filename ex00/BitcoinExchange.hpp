#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <exception>


class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void							parseRates(const std::string& filename);
		void							parseInput(const std::string& filename);
		std::pair<std::string, double>	parseRatesLine(const std::string& line);
		std::pair<std::string, double>	parseInputLine(const std::string& line);
		void							checkDateFormat(const std::string& date);


		class InvalidDateException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class InvalidValueException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

	private:
		std::map<std::string, double>	_btcInputData;
		std::map<std::string, double>	_btcRates;

};

#endif // BITCOINEXCHANGE_H
