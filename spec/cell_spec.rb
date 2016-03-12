require "minitest/autorun"
require "cell"

describe "Cell" do
  describe "Concept" do
    it "has a show method" do
      assert_equal "foobar", Cell::Concept.new.show
    end

    it "has a native show method" do
      assert_equal "foobar", Cell::Concept.new.native_show
    end

    it "has a collection method" do
      assert_equal ("foobar" * 5), Cell::Concept.collection(5)
    end

    it "has a native collection method" do
      assert_equal ("foobar" * 5), Cell::Concept.native_collection(5)
    end
  end

  describe "Benchmark" do
    require "benchmark/ips"

    it do
      skip
      Benchmark.ips do |x|
        x.report("show") { Cell::Concept.collection(50) }
        x.report("native_show") { Cell::Concept.native_collection(50) }
        x.compare!
      end
    end

    it do
      skip
      # concept = Cell::Concept.new
      Benchmark.ips do |x|
        x.report("show") { Cell::Concept.new.show }
        x.report("native_show") { Cell::Concept.new.native_show }
        x.compare!
      end
    end
  end
end
