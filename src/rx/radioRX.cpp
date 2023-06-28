
#include <rx/radioRX.h>



/* ----------RadioRX Member Function's Definitions---------- */
RadioRX::RadioRX(float Sample_Rate)
{
    sample_rate = Sample_Rate;
}


std::vector<std::complex<float>> RadioRX::receiveSamples()
{
    // We get the samples from the SDR's API here
    // {{-0.0118987,-0.0118987}, {-0.0142584,-0.0142584}, {0.00180723,0.00180723}, {0.0256811,0.0256811}, {0.0212171,0.0212171}, {-0.00797445,-0.00797445}, {-0.0432086,-0.0432086}, {-0.0552378,-0.0552378}, {-0.0353798,-0.0353798}, {0.0301317,0.0301317}, {0.110395,0.110395}, {0.139661,0.139661}, {0.0396217,0.0396217}, {-0.192555,-0.192555}, {-0.50495,-0.50495}, {-0.810719,-0.810719}, {-1.04235,-1.04235}, {-1.14293,-1.14293}, {-1.12029,-1.12029}, {-1.03341,-1.03341}, {-0.967349,-0.967349}, {-0.948036,-0.948036}, {-0.966691,-0.966691}, {-0.995299,-0.995299}, {-1.02395,-1.02395}, {-1.02895,-1.02895}, {-1.01171,-1.01171}, {-0.989015,-0.989015}, {-0.99083,-0.99083}, {-1.00327,-1.00327}, {-1.0099,-1.0099}, {-1.00327,-1.00327}, {-0.978931,-0.978931}, {-0.974757,-0.974757}, {-1.01351,-1.01351}, {-1.05464,-1.05464}, {-1.06896,-1.04516}, {-1.01584,-0.987325}, {-0.919868,-0.923482}, {-0.841436,-0.892798}, {-0.865737,-0.931969}, {-1.05097,-1.06354}, {-1.32072,-1.23069}, {-1.44443,-1.2826}, {-1.19517,-1.08197}, {-0.541951,-0.618163}, {0.307208,-5.93718e-09}, {1.00796,0.618163}, {1.23197,1.05817}, {0.837223,1.25408}, {-5.93718e-09,1.2343}, {-0.837223,1.1149}, {-1.25577,0.9982}, {-1.03648,0.905366}, {-0.303593,0.83345}, {0.593313,0.825487}, {1.2376,0.931969}, {1.42849,1.13085}, {1.2343,1.32072}, {0.940493,1.36455}, {0.794978,1.12893}, {0.901699,0.5579}, {1.14066,-0.220791}, {1.29516,-0.897486}, {1.172,-1.18501}, {0.698043,-0.926003}, {2.38651e-08,-0.217176}, {-0.698043,0.609262}, {-1.172,1.21896}, {-1.29516,1.40564}, {-1.14066,1.22708}, {-0.901699,0.917648}, {-0.818775,0.752544}, {-0.96901,0.889131}, {-1.23069,1.23069}, {-1.37712,1.457}, {-1.19517,1.2614}, {-0.609262,0.593313}, {0.217176,-0.303593}, {0.926003,-1.03648}, {1.20881,-1.25577}, {0.926003,-0.837223}, {0.217176,5.93718e-09}, {-0.609262,0.837223}, {-1.21896,1.25577}, {-1.40564,1.03648}, {-1.22708,0.303593}, {-0.917648,-0.593313}, {-0.776341,-1.2376}, {-0.917648,-1.42849}, {-1.22708,-1.2343}, {-1.40564,-0.940493}, {-1.19517,-0.794978}, {-0.580745,-0.901699}, {0.213562,-1.14066}, {0.874641,-1.29516}, {1.14258,-1.172}, {0.913435,-0.698043}, {0.307208,-2.38651e-08}, {-0.447425,0.698043}, {-1.10577,1.172}, {-1.48185,1.29516}, {-1.53428,1.14066}, {-1.30745,0.901699}, {-0.926344,0.794978}, {-0.472274,0.940493}, {0.00361446,1.2343}, {0.49512,1.42849}, {0.944981,1.2614}, {1.2915,0.62183}, {1.44787,-0.307208}, {1.37138,-1.08784}, {1.04691,-1.31011}, {0.521946,-0.835532}, {-0.0882244,0.0882244}, {-0.659793,0.973379}, {-1.06075,1.32395}, {-1.22326,0.939724}, {-1.18387,0.0432086}, {-1.03682,-0.876512}, {-0.920386,-1.30979}, {-0.92293,-1.02919}, {-1.03388,-0.200427}, {-1.12699,0.710129}, {-1.08478,1.25858}, {-0.862081,1.25188}, {-0.508564,0.815772}, {-0.164038,0.24025}, {0.0634191,-0.176613}, {0.139661,-0.301499}, {0.110395,-0.200427}, {0.0301317,-0.0175637}, {-0.0353798,0.101611}, {-0.0552378,0.1066}, {-0.0432086,0.046823}, {-0.00797445,-0.0205424}, {0.0212171,-0.0450145}, {0.0256811,-0.0256811}, {0.00180723,-0.00180723}, {-0.0142584,0.0142584}, {-0.0118987,0.0118987}};
    std::vector<std::complex<float>> samples = {{-0.0118987,-0.0118987}, {-0.0142584,-0.0142584}, {0.00180723,0.00180723}, {0.0256811,0.0256811}, {0.0212171,0.0212171}, {-0.00797445,-0.00797445}, {-0.0432086,-0.0432086}, {-0.0552378,-0.0552378}, {-0.0115824,-0.0115824}, {0.0586485,0.0586485}, {0.106781,0.106781}, {0.088299,0.088299}, {-0.0028124,-0.0028124}, {-0.176606,-0.176606}, {-0.418532,-0.418532}, {-0.700243,-0.700243}, {-0.995388,-0.995388}, {-1.23172,-1.23172}, {-1.33747,-1.33747}, {-1.26137,-1.26137}, {-0.980361,-0.980361}, {-0.550358,-0.550358}, {-0.046823,-0.046823}, {0.4643,0.4643}, {0.923764,0.947561}, {1.30461,1.33313}, {1.5397,1.53609}, {1.51896,1.46759}, {1.1363,1.09387}, {0.431476,0.447424}, {-0.393625,-0.307208}, {-1.02391,-0.913435}, {-1.16574,-1.11878}, {-0.757343,-0.846124}, {2.38651e-08,-0.217176}, {0.757344,0.529383}, {1.16574,1.10514}, {1.02391,1.36456}, {0.393625,1.32072}, {-0.431476,1.13085}, {-1.12441,0.955766}, {-1.5047,0.854004}, {-1.54151,0.829836}, {-1.33029,0.854004}, {-0.944981,0.955766}, {-0.456326,1.13085}, {0.0900316,1.32072}, {0.605595,1.36455}, {1.01574,1.10514}, {1.23123,0.529383}, {1.22708,-0.217176}, {1.09205,-0.846124}, {0.931969,-1.09498}, {0.864281,-0.884918}, {0.927096,-0.310822}, {1.03869,0.396062}, {1.0876,1.03954}, {1.03869,1.46928}, {0.927096,1.62431}, {0.864281,1.46928}, {0.931969,1.03954}, {1.09205,0.396062}, {1.22708,-0.310822}, {1.23123,-0.884918}, {1.03954,-1.11878}, {0.634112,-0.874641}, {0.0864172,-0.213562}, {-0.507688,0.580745}, {-1.03501,1.19517}, {-1.37138,1.40564}, {-1.44787,1.22708}, {-1.2915,0.917648}, {-0.968778,0.776341}, {-0.523637,0.917648}, {5.93718e-09,1.22708}, {0.523637,1.40564}, {0.992575,1.19517}, {1.32001,0.580745}, {1.44425,-0.213562}, {1.32001,-0.874641}, {0.980677,-1.13068}, {0.509378,-0.899176}, {0.00180723,-0.309015}, {-0.497956,0.421743}, {-0.947561,1.06075}, {-1.29947,1.46131}, {-1.49107,1.58111}, {-1.42661,1.41405}, {-1.07039,1.00416}, {-0.477556,0.426194}, {0.196812,-0.200427}, {0.773774,-0.745257}, {1.07916,-1.05536}, {1.03868,-1.03868}, {0.722126,-0.722126}, {0.281335,-0.281335}, {-0.086584,0.086584}, {-0.250137,0.250137}, {-0.196812,0.196812}, {-0.0460806,0.0460806}, {0.077814,-0.077814}, {0.1066,-0.1066}, {0.046823,-0.046823}, {-0.0205424,0.0205424}, {-0.0450145,0.0450145}, {-0.0256811,0.0256811}, {-0.00180723,0.00180723}, {0.0142584,-0.0142584}, {0.0118987,-0.0118987}};

    return samples;
}
