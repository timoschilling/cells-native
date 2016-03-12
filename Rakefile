require "rubygems"
require 'rake/testtask'
require 'rake/extensiontask'

Rake::ExtensionTask.new('cell_native')  do |ext|
  # ext.name = "cell/collection"
#   ext.name = 'cell-native'
#   ext.ext_dir = 'ext/cell'
  # ext.lib_dir = 'lib/cell'
  # ext.tmp_dir = "./tmp"
end

Rake::TestTask.new do |t|
  t.pattern = "spec/*_spec.rb"
end

# Rake::Task[:test].prerequisites << :clobber
# Rake::Task[:test].prerequisites << :compile

task default: [:clobber, :compile, :test]
