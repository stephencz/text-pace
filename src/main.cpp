/**
 * Command: text-pace
 * 
 * text-pace is a command line utility that is used to analyze the pacing
 * of plaintext and markdown files. The command is used as follows:
 * 
 * Usage: text-pace [-t TARGET] [-s PARAM]  [-o PARAM] [-c] 
 * 
 * text-pace always expects a target which should be a plaintext or markdown
 * file. By default, text-pace will use horizontal line partitions to visually
 * show the pacing of text. Additionally, it will output the document's word
 * count, paragraph count, and estimates of the reading time, exposition time,
 * and dialogue time based on a user set reading speed.
 * 
 * Options:
 * 
 * -c :
 * 
 *      The -c option will tell text-pace to use colors instead of horizontal
 *      line partitions.
 * 
 * -t [TARGET] : 
 * 
 *      The path to the file that should be analyzed. 
 * 
 * -o [PARAMS] : 
 * 
 *      The "only" option will skip the visual display of the target documents
 *      pacing, and instead output only the desired information. -o expects at
 *      least one of the following parameters:
 * 
 *          w - only word count
 *          p - only paragraph count
 *          r - only reading time
 *          d - only dialogue time
 *          e - only exposition time
 * 
 * -s [PARAM] :
 * 
 *      The -s option sets the reading speed that text-pace will use. This number should
 *      be set to the number of words the average reader can read in a minute. This
 *      typically falls between 200 and 300 WPM for the adult reader. 
 * 
 *      Default: 250
 * 
 * Examples:
 * 
 * text-pace -t chapter1.md :
 * 
 *      Outputs the visual and full analysis of the document using partitions at 250 WPM.
 * 
 * text-pace -t chapter1.md -c :
 * 
 *      Outputs the visual and full analysis of the document using colors at 250 WPM.
 * 
 * text-pace -t chapter1.md -c -s 150 :
 * 
 *      Outputs the visual and full analysis of the document using colors at 150 WPM.
 * 
 * text-pace -t chapter1.md -o wpr -s 300:
 * 
 *      Outputs only the word count, paragraph count, and reading time at 300 WPM.
 * 
 */

#include <iostream>
#include <string>

using namespace std;

struct Configuration {
  
    string target;

    int readingSpeed;

    bool useColors;

    bool onlyWordCount;

    bool onlyParagraphCount;

    bool onlyReadingTime;

    bool onlyExpositionTime;

    bool onlyDialogueTime;

};

Configuration newDefaultConfiguration() {
    return {
        "", 
        250,
        false,
        false,
        false,
        false,
        false,
        false
    };
}

Configuration parseArguments(int argc, char** argv) {
    
    Configuration config = newDefaultConfiguration();

    for(int i = 1; i < argc; ++i) {
        cout << argv[i] << " : " << i <<"\n";
    }

    return config;
}

int main(int argc, char** argv) {


    Configuration config = parseArguments(argc, argv);

    return 0;
}