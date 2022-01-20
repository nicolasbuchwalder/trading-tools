#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>

constexpr int num_args{6};

double getRatio(double last_traded, double price)
{
    return 100 * (price / last_traded - 1.0);
}

int main(int argc, char *argv[])
{
    if (argc != num_args)
    {
        std::cout << "Error: Please input ['last traded', 'num shares', 'costs', 'min profit', 'max loss']\n";
        return EXIT_FAILURE;
    }

    double last_traded{atof(argv[1])};
    double shares{atof(argv[2])};
    double costs{atof(argv[3])};
    double min_profit{atof(argv[4])};
    double max_loss{atof(argv[5])};

    std::cout << std::setprecision(4);

    double breakeven_price{last_traded + 2 * costs / shares};
    std::cout << "Breakeven price is: " << breakeven_price << " (" << getRatio(last_traded, breakeven_price) << "%)\n";
    double take_profit{(min_profit + 2 * costs) / shares + last_traded};
    std::cout << "Wanted take profit is: " << take_profit << " (" << getRatio(last_traded, take_profit) << "%)\n";
    double stop_loss{(2 * costs - max_loss) / shares + last_traded};
    std::cout << "Wanted stop loss is: " << stop_loss << " (" << getRatio(last_traded, stop_loss) << "%)\n";

    return 0;
}