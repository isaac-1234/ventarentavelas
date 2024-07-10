class VendedorVector {
public:
    // Constructor
    VendedorVector();

    // Destructor
    ~VendedorVector();

    // Member functions
    void addVendedor(const std::string& name, double sales);
    void printVendedores() const;
    double getTotalSales() const;

private:
    // Private data members
    std::vector<std::pair<std::string, double>> vendedores;
};