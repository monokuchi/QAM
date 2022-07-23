
#include <vector>

class Waveform
{
    private:
        // Private variables
        std::string name;
        int freq;
        std::vector<float> points;
        
    public:
        // Constructor
        Waveform (std::string name, int frequency, std::vector<float> points)
        {
            name = name;
            freq = frequency;
            points = points;
        }


        // Public functions
        std::string getName()
        {
            return name;
        }

        int getFreq()
        {
            return freq;
        }

        std::vector<float> getPoints()
        {
            return points;
        }


};