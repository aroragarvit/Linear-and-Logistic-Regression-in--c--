#ifndef DATALOADER_H
#define DATALOADER_H

class DataLoader
{
    public:
        //Loads a CSV File and converts it to Matrix
        static Matrix load_csv(std::string filename);
        //TODO: Implement Image Loaders
};
#endif