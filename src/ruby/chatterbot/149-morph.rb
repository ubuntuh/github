#!/usr/bin/env ruby
# coding: utf-8
require "open3"

module Morph
  def init_analyzer

  end

  def analyze(text)
    stdin, stdout, stderr, wait_thr = *Open3.popen3('chasen -F "%m %P-\t"')
    Thread.fork {
      stdin.print(text)
      stdin.close
    }
    analyzed = 'tmp'
    stdout.each do |line|
      analyzed = line
      break
    end
    
    # splitted = analyzed.chomp.split(/\t/)
    splitted = analyzed.chomp.scrub('?').split(/\t/)
    return splitted.map do |part|
      part.split(/ /)
    end
  end

  def keyword?(part)
    return /名詞-(一般|固有名詞|サ変接続|形容動詞語幹)/ =~ part
  end
  
  module_function :init_analyzer, :analyze, :keyword?
end

