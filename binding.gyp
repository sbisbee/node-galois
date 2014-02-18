{
  'targets': [
    {
      'target_name': 'galoisjs',
      'sources': [
        'deps/galois/galois.c',
        'src/galoisjs.cc',
      ],
      'include_dirs': [
        'deps/galois/',
      ],
    }
  ]
}
