# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/xenial64"
  config.vm.provider :virtualbox do |vb|
    vb.customize ["modifyvm", :id, "--memory", 4096, "--cpus", 2]
  end
  config.vm.network "private_network", ip: "192.168.33.10"
  config.vm.provision "shell", path: "vagrant_init.sh"
end