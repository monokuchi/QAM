
#include <vector>
#include <complex>


class Signal
{
    private:
        // Private variables
        std::string name;
        std::vector<std::complex<double>> signal_points;
        
    public:
        // Constructor
        Signal(std::string name)
        {
            name = name;
        }

        // Public functions
        std::string getName()
        {
            return name;
        }

        std::vector<std::complex<double>> getSignalPoints()
        {
            return signal_points;
        }

        void setSignalPoints(std::vector<std::complex<double>> points)
        {
            for (auto point = points.begin(); point != points.end(); ++point)
            {
                signal_points.push_back(*point);
            }
        }


};